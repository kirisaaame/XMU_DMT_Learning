/*
 * 3年　15組　96番　ゾウジファン
 * 出力：
 * カップラーメン : 180円
 * Java演習 : 2000円
 * カップラーメンとJava演習のセット : 2080円
 */
package javalec7;

import java.util.ArrayList;

class Food implements PriceTag {
	String name;
	int price;
	Food(String name, int price) {
		this.name = name; this.price = price;
	}
	public String tagstr() {
		return name;
	}
	public int price() { return price; }
}

class Book implements PriceTag{
	String name;
	int price;
	Book(String name, int price) {
		this.name = name; this.price = price;
	}
	public String tagstr() {
		return name;
	}
	public int price() { return price; }
}
class GoodsSet implements PriceTag {
	Food food;
	Book book;
	GoodsSet(Food food, Book book) {
		this.food = food;
		this.book = book;
	}
	public String tagstr() {
		return food.name + "と" + book.name + "のセット";
	}
	public int price() {
		return food.price + book.price - 100;
	}
}

interface PriceTag {
	String tagstr();
	int price();
}
public class ShopTest {
	public static void main(String[] args) {
		ArrayList<PriceTag> goods = new ArrayList<PriceTag>();
		Food f = new Food("カップラーメン", 180);
		goods.add(f);
		Book b = new Book("Java演習", 2000);
		goods.add(b);
		goods.add(new GoodsSet(f, b));

		for (PriceTag p : goods) {
			System.out.println(p.tagstr() + " : " + p.price() + "円");
		}
	}
}
