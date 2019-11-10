#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string basic_type;
    vector<string> var, add_type;
    
    cin>>basic_type;
    bool loop_on = 1;
    while(loop_on){
        string temp_var, temp_type;
        cin>>temp_var;
        if(temp_var.back()==';') loop_on = 0;
        temp_var.pop_back();
        for(int i=temp_var.size(); i>-1; i--){
            switch(temp_var[i]){
                case '*':
                case '&':
                    temp_type.push_back(temp_var[i]);
                    temp_var.pop_back();
                    break;
                case ']':
                    temp_type.push_back('[');
                    temp_type.push_back(']');
                    temp_var.pop_back();
                    temp_var.pop_back();
                    break;
            }
        }
        var.push_back(temp_var);
        add_type.push_back(temp_type);
    }
    
    for(int i=0; i<var.size(); i++){
        cout<<basic_type<<add_type[i]<<' '<<var[i]<<';'<<endl;
    }
    
    return 0;
}