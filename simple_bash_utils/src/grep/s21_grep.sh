#!/bin/bash

echo ----------------------------------------------*GREP 1
diff <(grep -v "pattern" test_files/1.txt) <(./s21_grep -v "pattern" test_files/1.txt) -s

echo ----------------------------------------------*GREP 2
diff <(grep -e a test_files/2.txt) <(./s21_grep -e a test_files/2.txt) -s

echo ----------------------------------------------*GREP 3
diff <(grep -i -v "pattern" test_files/3.txt) <(./s21_grep -i -v "pattern" test_files/3.txt) -s

echo ----------------------------------------------*GREP 4
diff <(grep -v "pattern" test_files/1.txt) <(./s21_grep -v "pattern" test_files/1.txt) -s

echo ----------------------------------------------*GREP 5
diff <(grep -c -v "pattern" test_files/2.txt) <(./s21_grep -c -v "pattern" test_files/2.txt) -s

echo ----------------------------------------------*GREP 6
diff <(grep -l "pattern" test_files/3.txt) <(./s21_grep -l "pattern" test_files/3.txt) -s

echo ----------------------------------------------*GREP 7
diff <(grep -n "pattern" test_files/1.txt) <(./s21_grep -n "pattern" test_files/1.txt) -s

echo ----------------------------------------------*GREP 8
diff <(grep -h "pattern" test_files/2.txt) <(./s21_grep -h "pattern" test_files/2.txt) -s

echo ----------------------------------------------*GREP 9
diff <(grep -s "pattern" test_files/3.txt) <(./s21_grep -s "pattern" test_files/3.txt) -s

echo ----------------------------------------------*GREP 10
diff <(grep -f "test_files/patterns.txt" test_files/1.txt) <(./s21_grep -f "test_files/patterns.txt" test_files/1.txt) -s

echo ----------------------------------------------*GREP 11
diff <(grep -o "pattern" test_files/2.txt) <(./s21_grep -o "pattern" test_files/2.txt) -s