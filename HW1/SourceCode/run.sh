#!/bin/bash
FOLDER=`ls ./puzzle`
echo "" > result.txt
for file in $FOLDER 
do
  echo $file >> result.txt
  ./sudoku.out ./puzzle/$file >> result.txt
  
done