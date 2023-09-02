package lab02;

import java.util.Scanner;

public class Lab02 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("이름을 입력하세요:");
		String name = scanner.nextLine();
		System.out.print("파일명을 입력하세요:");
		String filename = scanner.nextLine();

		String[] nameParts = name.split(" ");
		String firstName = nameParts[0];
		String middleName = nameParts[1];
		String lastName = nameParts[2];

		String newName = String.format("%s.%s.%s", firstName.substring(0,1).toUpperCase(), middleName.substring(0, 1).toUpperCase(),
				lastName.substring(0, 1).toUpperCase() + lastName.substring(1).toLowerCase());

		int koreanNameLength = nameParts.length;
		String newFilename = filename.replaceAll("homework.ppt", "Homework.pdf");
		newFilename = String.format("%s submitted %s", newName, newFilename);
		System.out.printf("Name Length (korean): %d\n", koreanNameLength);
		System.out.println(newFilename);
		scanner.close();
	}
}