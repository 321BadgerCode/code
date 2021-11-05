//badger
package main

import(
	"fmt"
	"strconv"
	"bufio"
	"os"
	"os/exec"
)

func pause(){
	fmt.Printf("[._.]: press any key to continue...")
	bufio.NewReader(os.Stdin).ReadBytes('\n')
}

func clear(){
	cmd:=exec.Command("cmd","/c","cls")
	cmd.Stdout=os.Stdout
	cmd.Run()
}

func print(a1 string){
	echo(a1+"\n")
}

func echo(a1 string){
	fmt.Printf(a1)
}

func get_string(a1 int) string {
	return strconv.Itoa(a1)
}

func get_sum_int_angle_polygon(side int) int {
	b1:=(side-2)*180
	return b1
}

func get_sum_ext_angle_polygon() int {
	return 360
}

func get_sum_int_angle_triangle(a1 int,a2 int) int {
	return 180-(a1+a2)
}

func main(){
	shape:=make(map[int]string)
	shape[3]="triangle"
	shape[4]="quadrilateral"
	shape[5]="pentagon"
	shape[6]="hexagon"
	shape[7]="heptagon"
	shape[8]="octagon"
	shape[9]="nonagon"
	shape[10]="decagon"
	shape[11]="hendecagon"
	shape[12]="dodecagon"

	a:=3
	for a<=12{
		print(get_string(a)+" sides("+shape[a]+") => sum int. ∠ poly.: "+get_string(get_sum_int_angle_polygon(a))+"°")
		a+=1
	}

	print("\nalso, the sum ext. ∠ poly.: "+get_string(get_sum_ext_angle_polygon())+"° for all polygons")

	print("\ninfo.: to use the \"sum int. ∠ poly.\", the poly. must have more than 3 sides(triangle(∆))")

	pause()
	clear()
}
//add onto/make better,etc.