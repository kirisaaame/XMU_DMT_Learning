package javalec4;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.List;
/* 3年　15組　96番　ゾウジファン
 出力：
 dup:
(6, 10)
(4, 2)
(16, 8)
(6, 6)
org:
(9, 15)
(6, 3)
(24, 12)
(9, 9)
dup:
(6, 10)
(4, 2)
(16, 8)
(6, 6)
 */
public class MultTest {
	
	static ArrayList<Pos> dup_mult(ArrayList<Pos> l, int m) {
		// ここを完成させよう
		ArrayList<Pos> ret = new ArrayList<>();
		for (Pos p : l) {
			ret.add(new Pos(p.x * m, p.y * m));
		}
		return ret;
	}
	static void modi_mult(ArrayList<Pos> l, int m) {
		// ここを完成させよう
		for (Pos p : l) {
			p.x *= m;
			p.y *= m;
		}

	}
	public static void main(String[] args) {
		ArrayList<Pos> org = new ArrayList<>(
				List.of(new Pos(3, 5), new Pos(2, 1), new Pos(8,4), new Pos(3, 3))
				);
		ArrayList<Pos> dup = dup_mult(org, 2);
		System.out.println("dup:");
		for (Pos p : dup) {
			System.out.println(p);
		}
		
		modi_mult(org, 3);
		System.out.println("org:");
		for (Pos p : org) {
			System.out.println(p);
		}		

		// 念のため表示してみる
		System.out.println("dup:");
		for (Pos p : dup) {
			System.out.println(p);
		}
	}

}
