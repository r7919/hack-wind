# EDIT these
extracted_cpp=190
random_tests=100
custom_hack=0
touch generator.cpp
touch correct.cpp


touch lily.cpp
touch hacks.txt
touch generated_input.txt
touch correct_output.txt
touch lily_output.txt
touch custom_input.txt

g++ generator.cpp -w -fsyntax-only -DONLINE_JUDGE -o generator
g++ correct.cpp -w -fsyntax-only -DONLINE_JUDGE -o correct

> log.txt
> hacks.txt
count_hacks=0

# Testing with random tests
for((i = 1;i <= $extracted_cpp;i++)) 
do
  printf "%s%s%s%s " "[" $i".cpp" "]" >> log.txt
	printf "%s%s%s%s " "[" $i".cpp" "]" 
	flag=0
	> lily.cpp
	cp trash/$i.cpp lily.cpp
    g++ lily.cpp -w -fsyntax-only -DONLINE_JUDGE -o lily
    for ((j = 1;j < random_tests;j++)) 
    do
      > generated_input.txt
      > lily_output.txt
      > correct_output.txt
      ./generator > generated_input.txt
      ./lily < generated_input.txt > lily_output.txt
      ./correct < generated_input.txt > correct_output.txt
      if diff -w lily_output.txt correct_output.txt
      then
         flag=1
      else
      	 flag=0
      	 ((count_hacks++))
         printf "%s%s%s%s " "[" $i".cpp" "]" >> hacks.txt
         printf "\n[***HACKED***]\n" >> hacks.txt
         printf "\n[***HACKED***]\n" >> log.txt
         printf "\n[***HACKED***]\n" 
         line=$(head -n 1 lily.cpp)
         printf "%s" $line >> hacks.txt
         printf "%s" $line 
         printf "\n" >> hacks.txt
         printf "\n" 
         cat generated_input.txt >> hacks.txt
         cat generated_input.txt 
         echo "[CORRECT_OUTPUT]"
         cat correct_output.txt >> hacks.txt
         cat correct_output.txt
         echo "[LILY OUTPUT]"
         cat lily_output.txt >> hacks.txt
         cat lily_output.txt
         printf "\n" >> hacks.txt
         printf "\n" 
         break
      fi
    done
    if [ $flag == 1 ]
    then
       printf "[-OK-]\n" >> hacks.txt
       printf "[-OK-]\n" >> log.txt
       printf "[-OK-]\n" 
    fi
done

