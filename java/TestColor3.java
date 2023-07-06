public class TestColor3{
	public static float get_pow(float base,int pow){
		if(pow!=0){
			return (base*get_pow(base,pow-1));
		}
		else{
			return 1;
		}
	}
	public static float get_abs(float n1){
	  return n1<0?-n1:n1;
	}
	public static boolean get_approx(float n1,float n2,float range){
	  return (get_abs(n1-n2))<=range;
	}
	public class Color{
		public static class Type{
			public static int fg=3;
			public static int bg=4;
		}

		public static class Rgb{
			public int r=0b00000000;
			public int g=0b00000000;
			public int b=0b00000000;

			public Rgb(int r2,int g2,int b2){
				r=r2;g=g2;b=b2;
			}
			public boolean get_approx_clr(Rgb rgb){
			    int range=10;
			    return get_approx(r,rgb.r,range)&&get_approx(g,rgb.g,range)&&get_approx(b,rgb.b,range);
			}
			public String get_name(){
			    String name=get_clr("R",Type.fg,red)+get_clr("G",Type.fg,green)+get_clr("B",Type.fg,blue);

			    if(get_approx_clr(white2)){name=get_clr("white",Type.fg,white);}
			    else if(get_approx_clr(black2)){name=get_clr("black",Type.fg,black);}
			    else if(get_approx_clr(red2)){name=get_clr("red",Type.fg,red);}
			    else if(get_approx_clr(orange2)){name=get_clr("orange",Type.fg,orange);}
			    else if(get_approx_clr(yellow2)){name=get_clr("yellow",Type.fg,yellow);}
			    else if(get_approx_clr(green2)){name=get_clr("green",Type.fg,green);}
			    else if(get_approx_clr(blue2)){name=get_clr("blue",Type.fg,blue);}
			    else if(get_approx_clr(indigo2)){name=get_clr("indigo",Type.fg,indigo);}
			    else if(get_approx_clr(violet2)){name=get_clr("violet",Type.fg,violet);}

                return name;
			}
			public int get_8_bit(){
				return ((r*0b001)/0xff)+((g*0b010)/0xff)+((b*0b100)/0xff);
			}
			@Override
            public String toString(){
                return  get_name()+
                        "("+
                        get_clr(String.valueOf(r),Type.fg,red)+get_clr(String.valueOf(g),Type.fg,green)+get_clr(String.valueOf(b),Type.fg,blue)+
                        ")";
            }
		}

		public static String begin="\u001B[";
		public static String end=begin+"0m";

		public static int white=0b111;
		public static int black=0b000;
		public static int red=0b001;
		public static int orange=0b011;
		public static int yellow=0b011;
		public static int green=0b010;
		public static int blue=0b100;
		public static int indigo=0b110;
		public static int violet=0b110;

		public static Rgb white2=new Rgb(255,255,255);
		public static Rgb black2=new Rgb(0,0,0);
		public static Rgb red2=new Rgb(255,0,0);
		public static Rgb orange2=new Rgb(255,125,0);
		public static Rgb yellow2=new Rgb(255,255,0);
		public static Rgb green2=new Rgb(0,255,0);
		public static Rgb blue2=new Rgb(0,0,255);
		public static Rgb indigo2=new Rgb(75,0,125);
		public static Rgb violet2=new Rgb(125,0,125);

		public static String get_clr(String txt,int type,int clr){
			return begin+type+clr+"m"+txt+end;
		}
	}
	@SafeVarargs
	public static <T> void print(T... a1){
        int a=0;
        for(T c:a1){
            System.out.print(a<a1.length-1?c+" ":c);
            a++;
        }
        System.out.print("\n");
    }
	public static void print(String[] a1,String[] a2){
        for(int a=0;a<a1.length;a++){
            System.out.print(a1[a]+"\t");
            System.out.print(a2[a]+"\n");
        }
    }
	public static void print(String a1,String a2){
		String b1[]=a1.split("\n");
		String b2[]=a2.split("\n");
        print(b1,b2);
    }
	public static String get_fmt(double d){
	    if(d==(long)d)
	        return String.format("%d",(long)d);
	    else
	        return String.format("%s",d);
	}
	public static String get_reverse(String a1){
        String b1="";
        for(int a=0;a<a1.length();++a){
            b1=a1.charAt(a)+b1;
        }
        return b1;
    }
    public static boolean is_palindrome(String a1){
        return a1.equals(get_reverse(a1));
    }
	public static void main(String[] args){
		print('a','b','c');
        print(1,2,3);

        print();

        print(get_reverse("tacocat"));
        print(get_reverse("test"));

        print();

        print(is_palindrome("tacocat"));
        print(is_palindrome("test"));

        print();

        print(new String[]{"test","cool"},new String[]{"test","nice"});
		print("*****\n*   *\n*   *\n*   *\n*****","test\ntet\ntest\n\ntest");

		try{
			print(Color.white2.toString());
			print(Color.black2.toString());
			print(Color.red2.toString());
			print(Color.orange2.toString());
			print(Color.yellow2.toString());
			print(Color.green2.toString());
			print(Color.blue2.toString());
			print(Color.indigo2.toString());
			print(Color.violet2.toString());
			print(new Color.Rgb(55,78,94).toString());
		}
		catch(Exception e){
			print("ERROR!!!");
		}
	}
}