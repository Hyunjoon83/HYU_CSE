package account;

import java.time.LocalDate;

public class Account {
	private String name;
	private double yearlyInterest;
	private double balance;
	private LocalDate created;
	
	public Account(String name, double yearlyInterest,LocalDate created) {
		this.name=name;
		this.yearlyInterest=yearlyInterest;
		this.balance=0;
		this.created=created;
	}
	
	public double getBalance() {
		return balance;
	}
	public LocalDate getCreated() {
		return created;
	}
	public void increaseYearlyInterest(int byPercent) {
		this.yearlyInterest += byPercent;
	}
	public void receiveIncome(double income) {
		this.balance += income*0.01;
	}
	public void receiveInterest() {
		double interest=balance*yearlyInterest/12;
		balance += interest;
	}
	public String toString() {
		return "이름: " +this.name+", 연이자: "+this.yearlyInterest+", 잔고: "+this.balance+", 가입일: "+this.created;
	}
	
}
