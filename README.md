# Lily-forces

- Codeforces has a feature of hacking, during contests. Here hacking doesn’t mean illegitimately breaking into a computer 
  system.
  
- In hacking, you can view the solution of others. If you think that you have a test case where the code may give the wrong answer.   Just click on the hack and provide your test case.

- After the end of the **Educational Rounds /  (Div. 3) rounds** there will be an 11-hour period of open hacks — any visitor of Codeforces may try to hack any complete solution to a problem of the last round (either from a contest, or practice), the source code of hacking solution is available (you can copy the text and, for example, stress it).

- This script helps in automating that process by scraping and extracting all the submissions of a particular problem and testing it on your local Linux machine.

## File Description

- This script can be used for random/custom testing, random testing uses `generator.cpp` which generates random inputs for the problem, contains many prewritten functions for generating PRNS, Random tree generator, shuffler. You can write your generator for a particular problem that you are testing.

- Before executing the script update `generator.cpp` and `correct.cpp` which contains the attacking code (possibly yours) for that problem.

- `lily.cpp` is a temporary file in the testing process which stores defender code temporarily.

## Executing

#### STEP 0

- Clone this repository to your local Linux machine and update `generator.cpp` and `correct.cpp` for that problem.
- Run `git clone https://github.com/ubc1729/Lily-forces.git`

#### STEP 1 

- Update `get_urls.py` by updating `contest_id`, `problem_id`, `page_start`, `page_end` variables.
- For example  `contest_id = 1324`, `problem_id = 560265`, `page_start = 1`, `page_end = 4`.
- `problem_id` can be obtained by inspecting (Ctrl + Shift + C)  the **Standings page** of that contest.
- Now run `python3 get_urls.py`
- The extracted URL's which are accepted submission URL's of that problem will be saved in `urls.txt` file.

#### STEP 2

- Run `python3 extract_source.py` 
- This filters and extracts the C++ source code of all the accepted submissions and saves them in `trash/` folder 

#### STEP 3

- Run `bash hack.sh` to test the submissions in `trash/` folder with 100 random inputs.  
- In `hack.sh` `random_tests`  is the number of random tests per defender code can be updated for intense testing it is set to 100 by default.
- `hack.sh` can be edited for further custom testing with a particular input.
- Successful hacks will be stored in the `hacks.txt` file, however, they will be displayed along with submission URL and Hacking input at the end of `hacks.sh` execution.

## Contributing    

- Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change and add.

- Please make sure to update the tests as appropriate.    

## References 

- [Codeforces](https://codeforces.com/)














