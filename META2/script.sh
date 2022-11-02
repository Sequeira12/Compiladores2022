#!/bin/bash


x=0;
for f in meta2testes; do
	x+=1;		
	./jucompiler f > x.txt 
done
