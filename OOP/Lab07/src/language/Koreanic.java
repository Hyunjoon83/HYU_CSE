package language;
	
public class Koreanic extends Language{
	public Koreanic(String name, int numSpeakers) {
		super(name, numSpeakers,Koreanic.getRegionsSpoken(name),"subject-object-verb");
	}
	private static String getRegionsSpoken(String name) {
		if(name.contains("Jeju")) {
			return new String("Jeju island");
		}else {
			return new String("Korean peninsula(South Korea, North Korea, Jeju) and several prefectures of China");
		}
	}
}