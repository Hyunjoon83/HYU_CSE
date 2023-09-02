package Assignment;

public class DigitObserver implements Observer{
	private NumberGenerator num;
	
	public DigitObserver(NumberGenerator num) {
		this.num=num;
		num.addObserver(this);
	}//num을 parameter로 받아서 num에 할당하고, 자기자신을 DigitObserver에 추가
	public void update(NumberGenerator generator) {
		System.out.println("DigitObserver: "+generator.getNumber());//generator에서 random으로 생성한 숫자를 출력
		try {
			Thread.sleep(100);//스레드를 100ms만큼 일시 정지 (일정한 시간 간격을 두고 update하기 위함)
		}catch(InterruptedException e) {
			e.printStackTrace();
		}
	}//interface의 update를 implement
}
