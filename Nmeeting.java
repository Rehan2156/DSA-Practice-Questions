class Meeting{
    //meeting class to hold 3 variables
    int start;
    int end;
    int pos;
    
    Meeting(int start,int end,int pos)
    {
        this.start=start;
        this.end=end;
        this.pos=pos;
    }
}
//comparator to compare start and end times
class MeetingComparator implements Comparator<Meeting>
{
    @Override
    public int compare(Meeting o1,Meeting o2)
    {
        //first we sort according to end times
        if(o1.end<o2.end)
            return -1;
        //if first one is greater then change it
        else if(o1.end>o2.end)
            return 1;
        //if both ending time are same then sort acc to position
        //this is rule. dont sort acc to starting time
        else if(o1.pos<o2.pos)
            return -1;
        return 1;
    }
}

class Solution 
{
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    public static int maxMeetings(int start[], int end[], int n)
    {
        // add your code here
        ArrayList<Meeting> meet = new ArrayList<>();
        
        //add data of meeting to array meet(start,end and index)
        for(int i=0;i<start.length;i++)
            meet.add(new Meeting(start[i],end[i],i+1));//i+1 bcoz 1 based indexing
        
        MeetingComparator mc = new MeetingComparator();
        Collections.sort(meet,mc);//sort it acc to our logic
        ArrayList<Integer> ans = new ArrayList<>();
        ans.add(meet.get(0).pos);//first meet will always be first so save the index
        int limit = meet.get(0).end;//save ending of meet into variable limit
        
        for(int i=1;i<start.length;i++)
        {
            if(meet.get(i).start>limit)//if start of one is greater than end of second then
            //that meeting can be done
            {
                limit = meet.get(i).end;
                ans.add(meet.get(i).pos);
            }
        }
        //now ans has all indexes of possible meetings
        //retur its size
        return ans.size();
    }
}
