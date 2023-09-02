package Iterator;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;

public class IteratorTest {
	public static void main(String[] args) {
		Scanner scan=new Scanner(System.in);
		String[] weeks= {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
		ArrayList<String> weekList=new ArrayList<>();
		for(String week:weeks)
			weekList.add(week);
		
		System.out.print("Write word that you want to find in list: ");
		int index=find(weekList,scan.nextLine());
		if(index==-1)
			System.out.println("Your word doesn'y exist in list.");
		else
			System.out.println("The word is found at index "+index);
	}
	public static int find(ArrayList<String> list,String search) {
		Iterator<String> iter=list.iterator();
		int count=0;
		while(iter.hasNext()) {
			String word=iter.next();
			if(word.equals(search))
				return count;
			count++;
		}
		return -1;
	}
}	
