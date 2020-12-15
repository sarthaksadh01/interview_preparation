bool solution(vector<int>&arrival,vector<int>&depart,int totalRooms){
    sort(begin(arrival),end(arrival));
    sort(begin(depart),end(depart));
    int maxRooms = 0,room = 0;
    int i = 0,j=0;
    while(i<n  && j<n){
        if(arrival[i] < depart[i])
            room++,i++;
        else room--,j++;
        maxRoom = max(room,maxRoom);
    }
    return maxRoom <=totalRooms;
}