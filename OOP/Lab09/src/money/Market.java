package money;

import java.util.Scanner;

public class Market {
	public static void main(String[] args) {
		Wallet wallet=new Wallet("My Wallet");
		Scanner scanner=new Scanner(System.in);
		while(true) {
			try {
				wallet.empty();
				System.out.print("Enter price: ");
				int price=scanner.nextInt();
			
				if(price<0) {
					throw new NegativeException();
				}else if(price>100) {
					throw new TooMuchExpenseException(price);
				}else if(price>0 && price<=wallet.getBalance()) {
					wallet.increaseIndex();
					wallet.decreaseBalance(price);
					System.out.println("peace~~");
				}else if(price>wallet.getBalance()) {
					throw new TooMuchExpenseException();
				}
			}catch(NegativeException e) {
				System.out.println(e.getMessage());
				System.out.println("oh,sorry!");
			}catch(TooMuchExpenseException e) {
				System.out.println(e.getMessage());
				if(e.getInputNum()>100) {
					System.out.println("You pay "+e.getInputNum());
				}
				System.out.println("oh, my!");
			}catch(Exception e) {
				if(e.getMessage().equals("Go Home")) {
					System.out.println(e.getMessage());
					System.out.println("the end...");
					scanner.close();
					return;
				}
			}
			finally {
				System.out.println(wallet.toString());
				System.out.println("---transcation complete---\n");
			}
		}
	}
}
