// 1845. Seat Reservation Manager

/*
	Input
	["SeatManager", "reserve", "reserve", "unreserve", "reserve", "reserve", "reserve", "reserve", "unreserve"]
	[[5], [], [], [2], [], [], [], [], [5]]
	Output
	[null, 1, 2, null, 2, 3, 4, 5, null]
*/

#include<bits/stdc++.h>
using namespace std;

class SeatManager {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    SeatManager(int n) {
        for(int i = 1;i<=n;i++){
            pq.push(i);
        }
    }
    
    int reserve() {
        int min = pq.top();
        pq.pop();
        return min;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};


int main(){

	SeatManager* seatManager = new SeatManager(5); // Initializes a SeatManager with 5 seats.
	cout<<seatManager->reserve()<<endl;    // All seats are available, so return the lowest numbered seat, which is 1.
	cout<<seatManager->reserve()<<endl;    // The available seats are [2,3,4,5], so return the lowest of them, which is 2.
	seatManager->unreserve(2); 			  // Unreserve seat 2, so now the available seats are [2,3,4,5].
	cout<<seatManager->reserve()<<endl;    // The available seats are [2,3,4,5], so return the lowest of them, which is 2.
	cout<<seatManager->reserve()<<endl;    // The available seats are [3,4,5], so return the lowest of them, which is 3.
	cout<<seatManager->reserve()<<endl;    // The available seats are [4,5], so return the lowest of them, which is 4.
	cout<<seatManager->reserve()<<endl;    // The only available seat is seat 5, so return 5.
	seatManager->unreserve(5);             // Unreserve seat 5, so now the available seats are [5].

	return 0;
}