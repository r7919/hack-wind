python3 animation.py
cd trash/
all_files=$(ls -1 | wc -l)
cd ..
printf "%s%s \n" "TOTAL FILES: " $all_files
# EDIT these
random_tests=100
custom_hack=0
extracted_cpp=$all_files
# extracted_cpp=79

touch generator.cpp
touch correct.cpp


touch lily.cpp
touch hacks.txt
touch generated_input.txt
touch correct_output.txt
touch lily_output.txt
touch custom_input.txt
touch custom_output.txt

g++ generator.cpp -DONLINE_JUDGE -o generator
g++ correct.cpp -DONLINE_JUDGE -o correct

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
    g++ lily.cpp -DONLINE_JUDGE -o lily
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
         printf "[***HACKED***]\n" >> log.txt
         printf "\n[***HACKED***]\n" 
         line=$(head -n 1 lily.cpp)
         printf "%s" $line >> hacks.txt
         printf "%s" $line 
         printf "\n" >> hacks.txt
         printf "\n" 
         echo "[INPUT]"
         echo "[INPUT]" >> hacks.txt
         cat generated_input.txt >> hacks.txt
         cat generated_input.txt 
         echo "[CORRECT_OUTPUT]"
         echo "[CORRECT_OUTPUT]" >> hacks.txt
         cat correct_output.txt >> hacks.txt
         cat correct_output.txt
         echo "[LILY OUTPUT]"
         echo "[LILY OUTPUT]" >> hacks.txt
         cat lily_output.txt >> hacks.txt
         cat lily_output.txt
         printf "\n" >> hacks.txt
         printf "\n" 
         break
      fi
    done
    if [ $flag == 1 ]
    then
       printf "[-OK-]\n" >> log.txt
       printf "[-OK-]\n" 
    fi
done

printf "%s%s \n" "TOTAL HACKS: " $count_hacks >> log.txt
printf "%s%s \n" "TOTAL HACKS: " $count_hacks >> hacks.txt
printf "%s%s \n" "TOTAL HACKS: " $count_hacks
echo "*--------------------LILY-FORCES---------------------------*"
cat hacks.txt
