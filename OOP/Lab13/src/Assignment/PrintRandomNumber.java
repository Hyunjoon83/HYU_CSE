package Assignment;

public class PrintRandomNumber {

	public static void main(String[] args) {
		NumberGenerator a=new RandomNumberGenerator();
		DigitObserver b=new DigitObserver(a);
		GraphObserver c=new GraphObserver(a);
		//RandomNumberGenerator, DigitObserver, GraphObserver 객체 생성
		a.execute();//a를 실행
	}
}
