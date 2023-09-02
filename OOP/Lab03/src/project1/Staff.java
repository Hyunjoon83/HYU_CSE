package project1;

public class Staff {

    private String name;
    private int age;
    private String department;
    private int workDays;
    private int vacationDays;

    public Staff(String name, int age) {
        this.name = name;
        this.age = age;
        this.department = "None";
        this.workDays = 0;
        this.vacationDays = 20;
    }

    public Staff(String name, int age, String department, int workDays, int vacationDays) {
        this.name = name;
        this.age = age;
        this.department = department;
        this.workDays = workDays;
        this.vacationDays = vacationDays;
    }

    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public int getAge() {
        return age;
    }
    public void setAge(int age) {
        this.age = age;
    }
    public String getDepartment() {
        return department;
    }
    public void setDepartment(String department) {
        this.department = department;
    }
    public int getWorkDays() {
        return workDays;
    }
    public void setWorkDays(int workDays) {
        this.workDays = workDays;
    }
    public int getVacationDays() {
        return vacationDays;
    }

    public boolean sameCareer(Staff other) {
        if (this.department.equals(other.department) && this.workDays == other.workDays) {
            return true;
        } else {
            return false;
        }
    }
    public String toString() {
        return String.format("Name: %s, Age: %d, Department: %s, WorkDays: %d, VacationDays: %d", name, age, department, workDays, vacationDays);
    }

    public void vacation(int days) {
        if (days <= vacationDays) {
            vacationDays -= days;
            System.out.printf("%s, 휴가 %d 사용. 남은 휴가 일수: %d%n", name, days, vacationDays);
        } else {
            System.out.printf("%s, 남은 휴가 일 수 부족.%n", name);
        }
    }
}