/*
 * 3年15組　96番 ゾウジファン　
 * 
 　　出力：
 	(3, 5)
	(2, 1)
	(3, 3)
	4
	3
 */

package javalec3;

import java.util.ArrayList;
import java.util.List;

public class FilterTest {
	
	static ArrayList<Pos> filter(ArrayList<Pos> l, int th) {
		ArrayList<Pos> res = new ArrayList<>();
		for (Pos p : l) {
			if (p.x <th && p.y < th) {
				res.add(p);
			}
		}
		return res;
	}

	public static void main(String[] args) {
		ArrayList<Pos> org = new ArrayList<>(
				List.of(new Pos(3, 5), new Pos(2, 1), new Pos(8,4), new Pos(3, 3))
				);
		ArrayList<Pos> conv = filter(org, 6);
		for (Pos p : conv) {
			System.out.println(p);
		}
		// もとのArrayListが書き換えられていないことも念のため確認しておこう
		System.out.println(org.size());
		System.out.println(conv.size());
	}

}
