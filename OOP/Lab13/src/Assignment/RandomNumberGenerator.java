package Assignment;

import java.util.Random;

public class RandomNumberGenerator extends NumberGenerator{
	private Random random=new Random();//Random 객체 생성
	private int number;
	
	public int getNumber() {
		return this.number;
	}//number를 반환하는 getNumber 메서드
	public void execute() {
		for(int i=0;i<10;i++) {
			this.number=random.nextInt(50);
			notifyObservers();
		}
	}//execute를 실행하면 50이내의 숫자가 random으로 number애 할당되고, notifyObserver를 호출한다.
}
