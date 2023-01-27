#include <iostream>
#include <iterator>
#include <map>
 
#include <sstream>
#include <string>
#include <stdio.h>
using namespace std;
bool checkError(string number){
    if(number.length() != 10) return false;
    for(int i=0;i<number.length();i++){
        int num = number[i] - '0';
        if(num < 0 || num > 9){
            return false;
        }
    }
    return true;
}
 
int countTime(string time_start, string time_end){
    int start_hour = (time_start[0] - '0')*10 +(time_start[1] -'0');
    int end_hour = (time_end[0] - '0')*10 +(time_end[1] -'0');
    int total_time = 0;
    int start_minute = (time_start[3] - '0')*10 + (time_start[4] - '0');
    int start_second = (time_start[6] - '0')*10 + (time_start[7] - '0');
    int end_minute = (time_end[3] - '0')*10 + (time_end[4] - '0');
    int end_second = (time_end[6] - '0')*10 + (time_end[7] - '0');
    if (start_hour >= end_hour){
        total_time += (end_hour * 3600 + end_minute * 60 + end_second) - (start_hour * 3600 + start_minute * 60 + start_second) ;
    } // neu call trong cung ngay
    else {
        int day_hour = 24;
        total_time += (day_hour * 3600 -(start_hour * 3600 + start_minute * 60 + start_second)) + (end_hour * 3600 + end_minute * 60 + end_second);
    } // neu call tu ngay cu sang moi, lay 24h - ngay cu + ngay moi
    return total_time;
}

int checkQuery(string query){
    string check_phone_number = "?check_phone_number";
    string number_calls_from = "?number_calls_from";
    string number_total_call = "?number_total_calls";
    string count_time_calls_from = "?count_time_calls_from";
    if (query.find(check_phone_number) == 0) return 1;
    if (query.find(number_calls_from) == 0) return 2;
    if (query.find(number_total_call) == 0) return 3;
    if (query.find(count_time_calls_from) == 0) return 4;
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int error_Num =0;
    int call_Num = 0;
    string type;
    string from_Num,to_Num,date,time_start,time_end;
 
    map<string,int> numberCalls,timeCalls;
    do {
        cin >> type;
        if(type != "#"){
            cin >> from_Num >> to_Num >> date >> time_start >> time_end;
            if(!checkError(from_Num) || !checkError(to_Num)){
                error_Num ++;
            }
            else{
                call_Num ++;
                numberCalls[from_Num]++;

                timeCalls[from_Num] +=countTime(time_start,time_end);
            }
        }
    }while (type != "#");
    // end block 1, read block 2

    
    string answer[100];
    int index =0;
    string query;
    do {
        getline(cin >> ws,type);
        if (type != "#"){
            int query = checkQuery(type);
            switch (query)
            {
            case 1:{
                if (error_Num != 0) {answer[index] = 0;}
                else{
                    answer[index] = 1;
                }
            }break;
            case 2:{
                string number_calls_from = "?number_calls_from";
                string phone_num = type.substr(number_calls_from.length()+1);
                answer[index] = numberCalls[phone_num];
            }break;
            case 3:{
                answer[index] = call_Num;
                break;
            }
            default:
                string count_time_calls_from = "?count_time_calls_from";
                string phone_num = type.substr(count_time_calls_from.length()+1);
                answer[index] = numberCalls[phone_num];
                break;
            }
            index++;
        }
    }while (type != "#");

    for (int i=0;i<index;i++){
        cout << answer[i] << endl;
    }
    return 0;
}
