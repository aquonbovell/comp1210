using System;

namespace comp1210.Models;
public class ClientData
{
  // Constants
  public static int RECORD_COUNT = 15;
  // Private fields
  private int accountNumber;
  private string lastName = string.Empty;
  private string firstName = string.Empty;
  private double balance;

  // Default constructor with optional parameters
  public ClientData(double balance = 0, string lastName = "", string firstName = "", int accountNumber = 0)
  {
    AccountNumber = accountNumber;
    LastName = lastName;
    FirstName = firstName;
    Balance = balance;
  }

  // AccountNumber property
  public int AccountNumber
  {
    get { return accountNumber; }
    set { accountNumber = value; }
  }

  // LastName property
  public string LastName
  {
    get { return lastName; }
    set { lastName = value.Length > 15 ? value[..15] : value; }
  }

  // FirstName property
  public string FirstName
  {
    get { return firstName; }
    set { firstName = value.Length > 10 ? value[..10] : value; }
  }

  // Balance property
  public double Balance
  {
    get { return balance; }
    set { balance = value; }
  }
}
