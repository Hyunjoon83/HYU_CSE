package manager;

import java.time.LocalDate;
import java.util.Random;

import account.Account;

public class AccountManager {
	public static void main(String[] args) {
		LocalDate created=LocalDate.of(2021,12,1);
		Account account=new Account("kim",5,created);
		System.out.println(account.toString());
				
		int flag=0;//특정 코드가 여러 번 실행되는 것을 방지하거나 이벤트가 한 번만 발생하도록 하는 데 사용
		int randomNumber=0;
		Random random=new Random();
		
		while(account.getBalance()<10000) {
			  account.receiveIncome(1);
			  account.receiveInterest();
			
			if(created.plusYears(3).isAfter(LocalDate.now())&&flag==0) {
				account.increaseYearlyInterest(2);
				flag=1;//조건 충족
				System.out.println("가입 후 3년이 지나서 이자율이 2%만큼 인상되었습니다.");
				created=created.plusYears(3);
			}
			if(created.plusYears(1).getYear() == LocalDate.now().getYear() && LocalDate.now().getMonthValue() == 1 && flag == 0) {
				randomNumber=random.nextInt(10);
				if(randomNumber==0){
					account.receiveIncome(100);
					System.out.println("이벤트 당첨!");
					flag=1;
				}
			}
		}
		System.out.println(account.toString());
	}
}

