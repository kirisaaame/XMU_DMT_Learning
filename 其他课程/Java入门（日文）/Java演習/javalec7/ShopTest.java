package javalec7;

import java.util.ArrayList;

class Food {
	String name;
	int price;
	Food(String name, int price) {
		this.name = name; this.price = price;
	}
	String tagstr() {
		return name;
	}
	int price() { return price; }
}

class Book {
	String name;
	int price;
	Book(String name, int price) {
		this.name = name; this.price = price;
	}
	String tagstr() {
		return name;
	}
	int price() { return price; }
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
