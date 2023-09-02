package Hash;

import java.util.*;

public class ListTest {

	public static void main(String[] args) {
		String[] months= {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
		ArrayList<String> subMonths=new ArrayList<>();
		subMonths.add("Sep");
		subMonths.add("Oct");
		subMonths.add("Nov");
		
		LinkedList <String> monthList=new LinkedList<>();
		for(String month:months) {
			monthList.add(month);
		}
		System.out.println("Size of LinkedList : "+monthList.size());
		System.out.println("Is monthList contains April : "+monthList.contains("April"));
		System.out.println("Is monthList contains 'Sep', 'Oct', 'Nov' : "+monthList.containsAll(subMonths));
		System.out.println("Remove 'Sep', 'Oct', 'Nov' from monthList");
		monthList.removeAll(subMonths);
		
		System.out.println("Values in monthList : "+monthList.toString());
	}

}
