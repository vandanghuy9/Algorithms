#include <bits/stdc++.h>

using namespace std;

bool checkPhone(string phoneNum){
    if(phoneNum.length() != 10) return false;
    for (int i = 0; i < phoneNum.length(); i++)
    {
        /* code */
        if(!(phoneNum[i] >= '0' && phoneNum[i] <= '9')) return false;
    }
    return true;
}

int countTime(string f_time, string e_time){
    int startTime = 3600 * ((f_time[0] - '0') * 10 + (f_time[1] - '0'))
                    + 60 * ((f_time[3] - '0') * 10 + (f_time[4] - '0'))
                    + ((f_time[6] - '0') * 10 + (f_time[7] - '0'));
    int endTime = 3600 * ((e_time[0] - '0') * 10 + (e_time[1] - '0'))
                    + 60 * ((e_time[3] - '0') * 10 + (e_time[4] - '0'))
                    + ((e_time[6] - '0') * 10 + (e_time[7] - '0'));
    return endTime - startTime;
}

map <string, int> numberCalls, timeCall;

int main(){
    ios_base::sync_with_stdio(0); // ????
    cin.tie(NULL); // ?
    cout.tie(NULL); // ?
    int incorrectPhone = 0;
    int totalCalls = 0;

    string type;
    do {
        cin >> type;
        if(type == "#") continue;
        ++totalCalls;
        string f_num, t_num, date, f_time, e_time;

        cin >> f_num >> t_num >> date >> f_time >> e_time;
        //cout << f_num << t_num << date << f_time << e_time << endl;
        if(!checkPhone(f_num) || !checkPhone(t_num)) ++incorrectPhone;
        numberCalls[f_num]++;
        timeCall[f_num] += countTime(f_time,e_time);

    } while(type != "#");

    do
    {
        /* code */
        cin >> type;
        if(type == "#") continue;
        if(type == "?check_phone_number"){
            if (incorrectPhone == 0) cout << 1 << endl;
            else cout << 0 << endl;
        }
        else if(type == "?number_calls_from"){
            string phone;
            cin >> phone;
            cout << numberCalls[phone] << endl;
        }
        else if(type == "?number_total_calls"){
            cout << totalCalls << endl;
        }
        else if(type == "?count_time_calls_from"){
            string phone;
            cin >> phone;
            cout << timeCall[phone] << endl;
        }
    } while (type != "#");
    

    return 0;
}