package lab11;

import java.util.ArrayList;
import java.util.Scanner;

public class Logistics {

	public static void main(String[] args) {
		String[] new_gyeonggi_boxes = { "SuWon#1", "SeongNam#1", "YongIn#1", "GoSeong#1", "GaPyeong#1" };
		String[] new_gangwon_boxes = { "Gangneung#1", "WonJu#1" };
		ArrayList<Gyeonggi> gyList = new ArrayList<>();
		ArrayList<Gangwon> gaList = new ArrayList<>();

		Scanner scan = new Scanner(System.in);
		int index1, index2;
		boolean gyIsPrinted = false;
		boolean gaIsPrinted = false;

		System.out.println("*** Oh, delivery price has been increased!! ***");
		
		ServiceManagement svcm = new ServiceManagement();
		
		svcm.packageBoxes(new_gyeonggi_boxes,Gyeonggi.class,gyList);
		svcm.packageBoxes(new_gangwon_boxes,Gangwon.class,gaList);
		gyList = svcm.raiseAll(Gyeonggi.class, gyList, 1.05);
		gaList = svcm.raiseAll(Gangwon.class, gaList, 1.05);

		System.out.println("Which box is important in Gangwon-area?");
		index1 = scan.nextInt();
		int gaIndex = svcm.findIndexByNum(gaList, index1);
		if (gaIndex >= 0 && gaIndex < gaList.size()) {
			Gangwon importantBox = gaList.get(gaIndex);
			int boxNumber = importantBox.getNumber();
			if (index1 == boxNumber) {
				System.out.println("The box\"" + importantBox.getDescription() + "\"is important! be careful!\n");
				importantBox = svcm.raisePerBox(importantBox, 1.2);
				gaList.set(gaIndex, importantBox);
			}
		} else if(gaIndex==-1){
			System.out.println("nothing");
		}

		System.out.println("Which box has the wrong area in Gyeonggi-area?");
		index2 = scan.nextInt();
		int gyIndex = svcm.findIndexByNum(gyList, index2);
		if (gyIndex >= 0 && gyIndex < gyList.size()) {
			Gyeonggi wrongBox = gyList.get(gyIndex)	;
			int boxNum = wrongBox.getNumber();
			if (index2 == boxNum) {
				System.out.println("The box\"" + wrongBox.getDescription() + "\"is actually has to go to Gangwon! late! hurry up!\n");
				wrongBox.setArea("Gangwon");
				wrongBox = svcm.raisePerBox(wrongBox, 0.9);
				svcm.packageBoxes(new String[]{wrongBox.getDescription()}, Gyeonggi.class, gyList);
		        svcm.changeHub(gyList, gyIndex, Gangwon.class, gaList);
		        gyList.set(gyIndex, null);
			}
		} else if(gyIndex==-1){
			System.out.println("nothing");
		}
		if (!gyIsPrinted) {
			System.out.println("-------- Delivery List for Gyeonggi --------");
			gyIsPrinted = true;
			for (Gyeonggi g : gyList) {
				System.out.println(g + "\n");
			}
		}
		if (!gaIsPrinted) {
			System.out.println("-------- Delivery List for Gangwon --------");
			gaIsPrinted = true;
			for (Gangwon j : gaList) {
				System.out.println(j + "\n");
			}
		}
		scan.close();
	}
}
