package Assignment;

public class GraphObserver implements Observer{
	private NumberGenerator num;
	
	public GraphObserver(NumberGenerator num) {
		this.num=num;
		num.addObserver(this);
	}//num을 parameter로 받아서 num객체에 저장하고, 자기 자신을 GraphObserver에 추가
	public void update(NumberGenerator generator) {
		System.out.print("GraphObserver: ");
		for(int i=0;i<generator.getNumber();i++){
			System.out.print("*");
		}//generator에서 random으로 생성한 숫자만큼 *을 출력
		System.out.println("");
		
		try {
			Thread.sleep(100);//스레드를 100ms만큼 일시 정지 (일정한 시간 간격을 두고 update하기 위함)
		}catch(InterruptedException e) {
			e.printStackTrace();
		}
	}//interface의 update를 implement
}
