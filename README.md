# PATlevelA
This repository include the answer of pat a level problems
package com.niit.javacourse.model;

public class Employee {
	private String name;
	private int salary;
	private String department;
	public Employee(String tName, int tSalasry, String tDepartment) {
		name = tName;
		salary = tSalasry;
		department = tDepartment;
	} 
	public void raiseSalary(int byPercent) {
		salary = salary + (salary * 100 / byPercent);
	}
	public void putN() {
		System.out.println(this.name);
	}
	public void putS() {
		System.out.println(this.salary);
	}
	public void putD() {
		System.out.println(this.department);
	}
}




package com.niit.javacourse.control;

import java.awt.DisplayMode;

import com.niit.javacourse.model.Employee;
import com.niit.javacourse.view.MainView;

public class Client {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Employee ztd = new Employee("捞人同德",100,"高宇部");
		ztd.raiseSalary(10);
		MainView oute = new MainView();
		oute.displayMainView(ztd);
	}
	

}





package com.niit.javacourse.view;

import com.niit.javacourse.model.Employee;

public class MainView {
	public void displayMainView(Employee sb) {
		sb.putN();
		sb.putS();
		sb.putD();
	}
}
