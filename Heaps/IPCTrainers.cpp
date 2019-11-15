#include<bits/stdc++.h>
using namespace std; 
#define ll long long int

ll test_cases,number_lecturers,days;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>test_cases;
    while(test_cases--)
    {
        cin>>number_lecturers>>days;
        vector<ll> sadness(number_lecturers), lectures(number_lecturers), startDay(number_lecturers);
        for(ll i = 0;i < number_lecturers; i++)
        {
            cin>>startDay[i]>>lectures[i]>>sadness[i];
            startDay[i]--;   // to make the start day count from 0
        }
        vector<pair<ll, ll> > persons;
        for(ll i = 0;i < number_lecturers;i++)
        {
            persons.push_back(make_pair(sadness[i],i));
        }
        sort(persons.rbegin(),persons.rend());
        vector<ll> lecturesTaken(number_lecturers);
        ll cur_day = 0;    // starting day be 0
        set<ll> daySet;
        for(ll i = 0;i < days;i++)
            daySet.insert(i);
        for(auto it:persons)
        {
            ll lec = lectures[it.second];
            for(ll i = 0;i < lec; i++)
            {
                auto iter = daySet.lower_bound(startDay[it.second]);
                if(iter == daySet.end())
                    break;
                else
                {    
                    lecturesTaken[it.second]++;
                    daySet.erase(iter);
                }
            }
        }
        ll ans = 0;
        for(ll i = 0;i < number_lecturers; i++)
        ans += (lectures[i] - lecturesTaken[i])*(sadness[i]);
        printf("%lld\n",ans);
    }
    return 0;
}