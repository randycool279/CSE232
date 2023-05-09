#include <iostream>
#include <string>



int main() {
    std::string input;
    std::getline(std::cin, input);
    char prev_char = '\0';
    int prev_run_length = 0;
    int run_length = 0;
    for (char c : input) {
        if (prev_char != c && prev_char != '\0') {
            if (run_length>prev_run_length) {
                int temp = run_length-prev_run_length;
                int temp1 = prev_run_length+1;
                for(int i=0; i<temp; i++){
                   std::cout << "'" << prev_char << "' is the first to length " << temp1 << std::endl;
                    temp1++;
                }
                prev_char = c;
                prev_run_length = run_length;
                run_length = 1;
            }  else{
                run_length=1;
                prev_char = c;
            } 
        } else {
            run_length++;
            prev_char = c;
        }
    }
    
    return 0;
}