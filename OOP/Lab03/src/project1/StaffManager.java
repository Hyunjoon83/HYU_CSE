package project1;

public class StaffManager {
    public static void main(String[] args) {
        Staff james = new Staff("James Wright", 29, "Accounting", 365, 15);
        Staff peter = new Staff("Peter Coolidge", 32, "R&D", 1095, 7);
        Staff amy = new Staff("Amy Smith", 27);

        System.out.println(james);
        System.out.println(peter);
        System.out.println(amy);
		
        System.out.println("---");
        
        if (amy.sameCareer(peter)) {
        	System.out.println("...A Few years later...");
            System.out.printf("%s and %s, Same.\n", amy.getName(), peter.getName());
        } else {
        	System.out.println("Same Career?");
            System.out.printf("%s and %s, Not exactly same.\n", amy.getName(), peter.getName());
        }
        
        amy.setDepartment(peter.getDepartment());
        amy.setWorkDays(peter.getWorkDays());

        if (amy.sameCareer(peter)) {
        	System.out.println("...A Few years later...");
            System.out.printf("%s and %s, Same.\n", amy.getName(), peter.getName());
        } else {
        	System.out.println("Same Career?");
            System.out.printf("%s and %s, Not exactly same.\n", amy.getName(), peter.getName());
        }
        System.out.println("---");
        
        james.vacation(10);
        amy.vacation(20);
        amy.vacation(1);
    }
}