#include <iostream>
#include <iterator>
#include <map>
 #include <utility>
#include <sstream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
typedef struct {
    string from_account;
    string to_account;
    int money;
}transaction;
bool checkError(string number){
    if(number.length() <6) return false;
    if (number.length() >20) return false;
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
    string number_transactions = "?number_transactions";
    string total_money_transaction = "?total_money_transaction";
    string list_sorted_accounts = "?list_sorted_accounts";
    string total_money_transaction_from = "?amount_money_trans_from";
    string inspect_cycle = "?inspect_cycle";
    if (query.find(number_transactions) == 0) return 1;
    if (query.find(total_money_transaction) == 0) return 2;
    if (query.find(list_sorted_accounts) == 0) return 3;
    if (query.find(total_money_transaction_from) == 0) return 4;
    if (query.find(inspect_cycle) == 0) return 5;
    return 0;
}

long amount_money_trans_from(transaction *data,string from_account,int number_of_transactions){
    long total_Money =0;
    for(int i=0;i<number_of_transactions;i++){
        if (data[i].from_account.find(from_account) == 0){
            total_Money += data[i].money;
        }
    }
    return total_Money;
}

void list_sorted_account(transaction *data,int number_of_transactions){
    std::vector<string> account;
    std::vector<string>::iterator it;
    for (int i=0;i<number_of_transactions;i++){
        it = std::find(account.begin(),account.end(),data[i].from_account);
        if (it != account.end()){
            continue;
        }
        else {
            account.push_back(data[i].from_account);
        }
        it = std::find(account.begin(),account.end(),data[i].to_account);
        if (it != account.end()){
            continue;
        }
        else {
            account.push_back(data[i].to_account);
        }
    }
    
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int error_Num =0;
    int call_Num = 0;
    // string type;
    int totalMoney = 0;
    string from_account,to_account,time_point,atm;
    int money;
    transaction data[100];
    int number_of_transaction=0;
    string answer[100];
    do {
        cin >> from_account;
        if(from_account != "#"){
            cin >> to_account >> money >> time_point >> atm;
            data[number_of_transaction].from_account = from_account;
            data[number_of_transaction].to_account = to_account;
            data[number_of_transaction].money = money;
            number_of_transaction++;
            totalMoney += money;
        }
    }while (from_account != "#");
    int index=0;
    string query;
    do {
        getline(cin >> ws,query);
        if (query != "#"){
            int query_type = checkQuery(query);
            switch (query_type)
            {
            case 1:{
                answer[index] = number_of_transaction;
            }break;
            case 2:{
                answer[index] = totalMoney;
            }break;
            case 4:{
                string amount_money = "?amount_money_trans_from";
                string find_account = query.substr(amount_money.length()+1);
                long total_amount = amount_money_trans_from(data,find_account,number_of_transaction);
                answer[index] = total_amount;
                break;
            }
            default:{
        
            }
            index++;
            }
        }
    }while (query != "#");
    // end block 1, read block 2
    return 0;
}
