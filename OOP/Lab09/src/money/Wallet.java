package money;

public class Wallet {
	private String name;
	private int balance;
	private int txIndex;
	
	public Wallet(String name) {
		this.name=name;
		this.txIndex=0;
		this.balance=100;
	}
	public int getBalance() {
		return this.balance;
	}
	public void increaseIndex() {
		this.txIndex++;
	}
	public void decreaseBalance(int expense){
		this.balance-=expense;
	}
	public String toString() {
		return "name: "+this.name+", #"+this.txIndex+", balance: "+this.balance;
	}
	public void empty() throws Exception{
		if(this.balance<=0) {
			throw new Exception("Go Home");
		}
			
	}
}
