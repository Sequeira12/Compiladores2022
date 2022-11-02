#!/bin/bash
# Compara o output do programa com o output esperado para cada
#   ficheiro na input/output directory a configurar em baixo
# Os ficheiros de input tem que ter extensao .java ou .juc
#   os de output .out
# Antes de executar o scrip adicionar permissoes com
#   chmod +x ./test.sh
# Usage: ./test.sh
# Args:     -e          imprime os erros (off por default)
#           -t [name]   ficheiro especifico, nao é necessário
#                           adicionar a extensao.
#                           ex: ./test.sh -t EsteEPuxado
#           -a "args"   executa o jucompiler com os args especificos
#                           ex: ./test.sh -a "-e1"
#                           args está com "-l" por default
#                           para executar sem argumentos nenhums podem
#                           fazer: ./test.sh -a
#
# Nota: há um makefile que deve estar na mesma diretoria
# Nota: há alguns casos de teste cujo ouput não tem um /n no final,
#       o que pode dar um false negative.
#       verifiquem as diferenças com ./test.sh -t nome_do_teste -e
# Oleksandr Yakovlyev 2020 Universidade de Coimbra

# CONFIGURAR PARA A DIRETORIA ONDE TEM OS TESTES
in_dir="meta1"
out_dir="meta1out"

# Reset
Color_Off='\033[0m'       # Text Reset
Red='\033[0;31m'          # Red
Green='\033[0;32m'        # Green
Yellow='\033[0;33m'       # Yellow

show_errors=''
compile_debug=''
specific_test=''
diff_args=''

prog="jucompiler"
args="-l"
only_error_files=["InsertionSort"]

run_test(){
    in_file=$1
    out_file="${in_file%.juc}"
    out_file="${out_file%.java}"
    out_file="$out_file.out"
    
    diff -y $diff_args <( ./$prog $args < "$in_dir/$in_file" ) $out_dir/$out_file &> $outputfile
    error=$?
    if [ $error -eq 0 ]
    then
        let tests_made=$tests_made+1
        let tests_passed=$tests_passed+1
        echo -e ✅ "${Green}PASS${Color_Off}" $(basename $in_file)
    elif [ $error -eq 1 ]
    then
        let tests_made=$tests_made+1
        echo -e ❌ "${Red}FAIL${Color_Off}" $(basename $in_file)
        if [ "$show_errors" = 'true' ]
        then
            cat $outputfile
            echo ""
        fi
    else
        echo -e ⚡ "${Yellow}WARN${Color_Off}" $(basename $in_file) \
        "Something went wrong: $(cat $outputfile)"
    fi
}

while getopts 'edst:a' flag; do
    case "$flag" in
        e) show_errors='true' ;;
        d) compile_debug='true' ;;
        t) specific_test="$OPTARG" ;;
        s) diff_args='--suppress-common-lines' ;;
        a) args="$OPTARG" ;;
    esac
done

if [ "$compile_debug" = 'true' ]
then
    echo "Recompiling in debug..."
    make debug
else
    echo "Recompiling ..."
    make
fi
error=$?
if [ $error -ne 0 ]
then
    exit
fi
echo "Done."

if [ "$args" != '' ]
then
    echo "Running program with flag : $args"
fi

outputfile="temp.txt" #TODO change to pipe
# mkfifo falha em subdiretorias do windows ( usando WSL )
# por isso fica em ficheiro por enquanto

if [ "$specific_test" != '' ]
then
    specific_test=$(ls $in_dir | grep "$specific_test.[j]")
    
    run_test $specific_test
    rm temp.txt
    exit
fi

printf "\t Tests:\n"
tests_made=0
tests_passed=0
for in_file in $in_dir/*.{juc,java} ; do
    #echo $(basename $in_file)
    in_file=$(basename "$in_file")
    run_test $in_file
done

echo ""
echo "Total $tests_passed/$tests_made ("`echo "$tests_passed*100/$tests_made" | bc`"%)"

rm $outputfile
