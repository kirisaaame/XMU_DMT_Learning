package javalec5;
/*
 * 3年　15組　96番　ゾウジファン
 * 出力：
きのこのこ
のこのこのこ
 */
import java.util.ArrayList;
import java.util.List;
public class StringTest {
	public static void main(String[] args) {
		List<String> list = new ArrayList<String>();
		for (int i = 0; i < Parts.NUM; i++) {
			for(int j = 0; j < Parts.NUM; j++) {
				String s = Parts.item(i) + Parts.item(j);
				list.add(s);
			}
		}
		List<String> list2 = new ArrayList<String>();
		for (int i = 0; i < list.size(); i++) {
			String current = list.get(i);
			if (list.subList(i + 1, list.size()).contains(current) && !list2.contains(current)) {
				list2.add(current);
			}
		}
		for (String s : list2) {
			System.out.println(s);
		}
	}
}