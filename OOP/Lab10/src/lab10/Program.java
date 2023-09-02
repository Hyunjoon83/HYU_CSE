package lab10;

public class Program {
	public static void main(String[] args) {
		Dog dog=new Dog();
		Tiger tiger=new Tiger();
		Turtle turtle=new Turtle();
		
		Animal[] animals=new Animal[3];
		animals[0]=dog;
		animals[1]=tiger;
		animals[2]=turtle;
		
		Person person=new Person() {
			private int hp=100;
			public void control(Animal animal) {
				if(animal instanceof Tiger) {
					hp-=80;
					System.out.println("You have overpowered the Tiger");
				}else if(animal instanceof Dog) {
					hp-=10;
					System.out.println("You have overpowered the Dog");
				}else if(animal instanceof Turtle) {
					System.out.println("You have overpowered the Turtle");
				}
			}
			public void showInfo() {
				System.out.println("Person HP: "+hp);
			}
		};
		showResult(animals,person);
	}
	private static void showResult(Animal[] animals, Person person) {
			for(int i=0;i<animals.length;i++) {
				Animal animal=animals[i];
				System.out.println("Animal"+(i+1)+":"+animal.getName());
				if(animal instanceof Barkable) {
					Barkable barkableAnimal=(Barkable) animal;//객체 타입 확인 (interface 타입으로 자동 타입 변환된 매개값을 메소드 내에서 다시 구현 클래스 타입으로 강제 타입 변환을 해야 하는 경우)
					System.out.println("Animal"+(i+1)+" barked "+barkableAnimal.bark());
				}
			person.control(animal);
			person.showInfo();
			}
	}
}
