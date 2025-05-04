using System.Text;
using comp1210.Models;

namespace comp1210;

public enum Choice
{
	PRINT = 1,
	UPDATE,
	NEW,
	DELETE,
	END
}

class Program
{
	static void Main(string[] args)
	{
		// Inhertiance();

		// FileIO();

		// Recursion();

		// Sort();

		// Arrays();

		CreditProcessing();
	}
	public static void Inhertiance()
	{
		House house = new("456 Luxury Ave", 10, 500000.00);

		Mansion mansion = new("456 Luxury Ave", 10, 500000.00)
		{
			LuxuryFee = 200000,
			SwimmingPools = 2
		};

		Console.WriteLine(house);
		Console.WriteLine(mansion);

		Package FedEx = new("John Doe", "123 Main St", "Anytown", "CA", "12345",
			"Jane Smith", "456 Elm St", "Othertown", "NY", "67890",
			10, 5.00);

		OvernightPackage DHL = new("John Doe", "123 Main St", "Anytown", "CA", "12345",
		"Jane Smith", "456 Elm St", "Othertown", "NY", "67890", 34, 4.50, 20.00);

		TwodayPackage UPS = new("John Doe", "123 Main St", "Anytown", "CA", "12345",
			"Jane Smith", "456 Elm St", "Othertown", "NY", "67890",
			10, 5.00, 10.00);

		Console.WriteLine(FedEx);
		Console.WriteLine(DHL);
		Console.WriteLine(UPS);
	}

	public static void FileIO()
	{
		// int largeNumber, number;
		// try
		// {
		// 	using StreamReader stream = new("Files/input.txt");
		// 	string? line;
		// 	Console.WriteLine("Processing file...");
		// 	line = stream.ReadLine();
		// 	if (line == null)
		// 	{
		// 		Console.WriteLine("No data found in the file.");
		// 		Console.WriteLine("Processing complete.");
		// 		return;
		// 	}
		// 	number = int.Parse(line);
		// 	largeNumber = number;
		// 	while ((line = stream.ReadLine()) != null)
		// 	{
		// 		number = int.Parse(line);
		// 		if (number > largeNumber)
		// 		{
		// 			largeNumber = number;
		// 		}
		// 	}

		// 	stream.Close();

		// 	using StreamWriter stream1 = new("Files/output.txt");

		// 	stream1.WriteLine(largeNumber);

		// 	stream1.Close();

		// 	Console.WriteLine("Processing complete.");
		// }
		// catch (DirectoryNotFoundException)
		// {
		// 	Console.WriteLine("Directory not found.");
		// }
		// catch (UnauthorizedAccessException)
		// {
		// 	Console.WriteLine("Access denied to the file.");
		// }
		// catch (FileNotFoundException)
		// {
		// 	Console.WriteLine("File not found.");
		// }
		// catch (IOException ex)
		// {
		// 	Console.WriteLine($"IO Exception: {ex.Message}");
		// }
		// catch (Exception ex)
		// {
		// 	Console.WriteLine($"General Exception: {ex.Message}");
		// }

		int acctNumber;
		decimal currentBalance, dollarAmount;
		bool found = false;
		string name;
		try
		{
			using StreamReader oldMast = new("Files/oldmast.txt");
			using StreamWriter newMast = new("Files/newmast.txt");
			using StreamReader trans = new("Files/trans.txt");
			string? line;
			Console.WriteLine("Processing file...");
			line = oldMast.ReadLine();
			if (line == null)
			{
				Console.WriteLine("No data found in the file.");
				Console.WriteLine("Processing complete.");
				return;
			}
			while (line != null)
			{
				string[] parts = line.Split(',');

				acctNumber = int.Parse(parts[0].Trim());

				name = parts[1].Trim();

				currentBalance = decimal.Parse(parts[2].Trim());

				line = trans.ReadLine();
				while (line != null)
				{
					string[] transaction = line.Split(',');

					if (acctNumber == int.Parse(transaction[0].Trim()))
					{
						currentBalance += decimal.Parse(transaction[1].Trim());
					}
					line = trans.ReadLine();
				}

				trans.BaseStream.Seek(0, SeekOrigin.Begin);

				newMast.WriteLine($"{acctNumber}, {name}, {currentBalance:.2}");

				line = oldMast.ReadLine();
			}

			oldMast.BaseStream.Seek(0, SeekOrigin.Begin);
			trans.BaseStream.Seek(0, SeekOrigin.Begin);

			newMast.Close();

			line = trans.ReadLine();
			while (line != null)
			{
				string[] parts = line.Split(',');

				acctNumber = int.Parse(parts[0].Trim());

				dollarAmount = decimal.Parse(parts[1].Trim());

				line = oldMast.ReadLine();
				while (line != null && !found)
				{
					string[] customer = line.Split(',');

					found = acctNumber == int.Parse(customer[0].Trim());

					line = oldMast.ReadLine();
				}

				if (found == false)
				{
					Console.WriteLine($"Unmatched transaction record for account: {acctNumber}");
				}
				found = false;

				oldMast.BaseStream.Seek(0, SeekOrigin.Begin);

				line = trans.ReadLine();
			}


			// stream.Close();

			// using StreamWriter stream1 = new("Files/newmast.txt");

			// stream1.Close();

			oldMast.Close();
			trans.Close();

			Console.WriteLine("Processing complete.");
		}
		catch (DirectoryNotFoundException)
		{
			Console.WriteLine("Directory not found.");
		}
		catch (UnauthorizedAccessException)
		{
			Console.WriteLine("Access denied to the file.");
		}
		catch (FileNotFoundException)
		{
			Console.WriteLine("File not found.");
		}
		catch (IOException ex)
		{
			Console.WriteLine($"IO Exception: {ex.Message}");
		}
		catch (Exception ex)
		{
			Console.WriteLine($"General Exception: {ex.Message}");
		}
	}

	public static void Recursion()
	{
		static Int128 SumSquared(int n)
		{
			if (n == 1)
				return 1;
			else
				return (n * n) + SumSquared(n - 1);
		}

		static Int128 Power(int x, int y)
		{
			if (y == 0)
				return 1;
			else
				return x * Power(x, y - 1);
		}

		static Int128 Factorial(int n)
		{
			if (n == 0 || n == 1)
				return 1;
			else
				return n * Factorial(n - 1);
		}

		// // Iterative version of Factorial for large numbers
		// static Int128 Factorial(int n)
		// {
		// 	Int128 result = 1;
		// 	for (int i = 1; i <= n; i++)
		// 	{
		// 		result *= i;
		// 	}
		// 	return result;
		// }

		static Int128 GreatestCommonDivisor(int a, int b)
		{
			if (b == 0)
				return a;
			else
				return GreatestCommonDivisor(b, a % b);
		}

		Console.WriteLine("Enter a number to calculate the sum of squares: ");
		int n = int.Parse(Console.ReadLine()!);
		Int128 result = SumSquared(n);
		Console.WriteLine($"The sum of squares from 1 to {n} is: {result}");
	}

	public static void Sort()
	{
		decimal[] z = [100.2m, 1.6m, 82.6m, 7.9m, 74.6m, 89.1m, 83.5m, 68.4m, 18.0m, 61.6m, 15.6m, 97.7m, 6.2m, 64.5m, 45263.9m, 55m, 19.9m, 8.1m, 3.561m, 00.2m, 1.6m, 82.6m, 7.9m, 74.6m, 89.1m, 83.5m, 68.4m, 18.0m, 61.6m, 15.6m, 97.7m, 6.2m, 64.5m, 63.9m, 55m, 34.95m, 19.9m, 8.1m, 4m, 6m, 68m];
		Array.Sort(z);

		Console.WriteLine("Sorted array: ");
		foreach (decimal i in z)
		{
			Console.WriteLine(i);
		}
		Console.WriteLine("Sorted array in reverse order: ");
		Array.Reverse(z);
		foreach (decimal i in z)
		{
			Console.WriteLine(i);
		}
	}

	public static void Arrays()
	{
		decimal[] numbers = [100.2m, 1.6m, 82.6m, 7.9m, 74.6m, 89.1m, 83.5m, 68.4m, 18.0m, 61.6m, 15.6m, 97.7m, 6.2m, 64.5m, 63.9m, 55m, 34.95m, 19.9m, 8.1m, 3.56m];

		decimal smallest = numbers[0];
		decimal largest = numbers[0];

		foreach (var item in numbers)
		{
			if (item < smallest)
			{
				smallest = item;
			}
			if (item > largest)
			{
				largest = item;
			}
		}

		Console.WriteLine($"Smallest number: {smallest}");
		Console.WriteLine($"Largest number: {largest}");
	}

	public static void CreditProcessing()
	{
		string filePath = Path.Combine(Directory.GetCurrentDirectory(), "Files", "credit.txt");

		static void InData(string filePath)
		{
			Console.WriteLine("Processing file...");
			using FileStream fs = new(filePath, FileMode.OpenOrCreate, FileAccess.ReadWrite);
			using BinaryWriter writer = new(fs);

			Console.WriteLine("Enter account number (1 to 100, 0 to end input)");
			Console.Write("? ");
			int accountNumber = int.Parse(Console.ReadLine() ?? string.Empty);

			while (accountNumber > 0 && accountNumber <= 100)
			{
				Console.WriteLine("Enter lastname, firstname and balance");
				Console.Write("? ");
				string lastName = Console.ReadLine() ?? string.Empty;
				string firstName = Console.ReadLine() ?? string.Empty;
				double balance = double.Parse(Console.ReadLine() ?? string.Empty);

				// Create ClientData object
				ClientData client = new(balance, lastName, firstName, accountNumber);

				// Seek to the position in the file
				long position = (client.AccountNumber - 1) * GetRecordSize();
				fs.Seek(position, SeekOrigin.Begin);

				// Write client data
				WriteClientData(writer, client);

				Console.WriteLine("Enter account number");
				Console.Write("? ");
				accountNumber = int.Parse(Console.ReadLine() ?? string.Empty);
			}

			Console.WriteLine("Processing complete.");
		}

		static void OutData(string filePath)
		{
			Console.WriteLine("Reading file...\n");

			if (!File.Exists(filePath))
			{
				Console.WriteLine("File could not be opened.");
				return;
			}

			using FileStream fs = new(filePath, FileMode.Open, FileAccess.Read);
			using BinaryReader reader = new(fs);

			// Output column headers
			Console.WriteLine("{0,-10}{1,-16}{2,-11}{3,10}", "Account", "Last Name", "First Name", "Balance");

			while (fs.Length - fs.Position >= GetRecordSize())

			{
				ClientData client = ReadClientData(reader);

				if (client.AccountNumber != 0)
				{
					OutputLineToConsole(client);
				}
			}
		}

		static void Credit(string filePath)
		{
			// Create or overwrite the file with 100 blank ClientData records
			using FileStream fs = new(filePath, FileMode.Create, FileAccess.Write);
			using BinaryWriter writer = new(fs, Encoding.ASCII); // ASCII like C++

			ClientData blankClient = new(); // All default/empty values

			for (int i = 0; i < ClientData.RECORD_COUNT; i++)
			{
				WriteClientData(writer, blankClient);
			}

			Console.WriteLine("100 blank records written to credit.txt");
		}

		static void Transactions(string filePath)
		{
			if (!File.Exists(filePath))
			{
				Credit(filePath);
			}

			using FileStream fs = new(filePath, FileMode.Open, FileAccess.ReadWrite);
			using BinaryReader reader = new(fs);
			using BinaryWriter writer = new(fs);

			Choice choice;
			while ((choice = EnterChoice()) != Choice.END)
			{
				switch (choice)
				{
					case Choice.PRINT:
						CreateTextFile(fs);
						break;
					case Choice.UPDATE:
						UpdateRecord(fs);
						break;
					case Choice.NEW:
						NewRecord(fs);
						break;
					case Choice.DELETE:
						DeleteRecord(fs);
						break;
					default:
						Console.WriteLine("Incorrect choice.");
						break;
				}
			}
		}

		static Choice EnterChoice()
		{
			Console.WriteLine("\nEnter your choice\n" +
					"1 - store a formatted text file of accounts\n" +
					"    called \"print.txt\" for printing\n" +
					"2 - update an account\n" +
					"3 - add a new account\n" +
					"4 - delete an account\n" +
					"5 - end program\n? ");
			return (Choice)int.Parse(Console.ReadLine() ?? "5");
		}
		static void CreateTextFile(FileStream fs)
		{
			fs.Seek(0, SeekOrigin.Begin);
			using StreamWriter textFile = new("print.txt");

			textFile.WriteLine("{0,-10}{1,-16}{2,-11}{3,10}", "Account", "Last Name", "First Name", "Balance");

			using BinaryReader reader = new(fs, Encoding.Default, leaveOpen: true);

			// Ensure that there is enough data left to read the full record before each read.
			while (fs.Position + GetRecordSize() <= fs.Length)
			{
				ClientData client = ReadClientData(reader);
				if (client.AccountNumber != 0)
				{
					OutputLine(textFile, client);
				}
			}
		}


		static void UpdateRecord(FileStream fs)
		{
			int accountNumber = GetAccount("Enter account to update");
			long position = (accountNumber - 1) * GetRecordSize();

			fs.Seek(position, SeekOrigin.Begin);
			using BinaryReader reader = new(fs, Encoding.Default, leaveOpen: true);
			ClientData client = ReadClientData(reader);

			if (client.AccountNumber != 0)
			{
				OutputLine(Console.Out, client);
				Console.Write("\nEnter charge (+) or payment (-): ");
				double transaction = double.Parse(Console.ReadLine() ?? "0");

				client.Balance += transaction;

				fs.Seek(position, SeekOrigin.Begin);
				using BinaryWriter writer = new(fs, Encoding.Default, leaveOpen: true);
				WriteClientData(writer, client);

				OutputLine(Console.Out, client);
			}
			else
			{
				Console.WriteLine($"Account #{accountNumber} has no information.");
			}
		}


		static void NewRecord(FileStream fs)
		{
			int accountNumber = GetAccount("Enter new account number");
			long position = (accountNumber - 1) * GetRecordSize();

			fs.Seek(position, SeekOrigin.Begin);
			using BinaryReader reader = new(fs, Encoding.Default, leaveOpen: true);
			ClientData client = ReadClientData(reader);

			if (client.AccountNumber == 0)
			{
				Console.Write("Enter lastname, firstname, balance\n? ");
				string lastName = Console.ReadLine() ?? "";
				string firstName = Console.ReadLine() ?? "";
				double balance = double.Parse(Console.ReadLine() ?? "0");

				ClientData newClient = new(balance, lastName, firstName, accountNumber);

				fs.Seek(position, SeekOrigin.Begin);
				using BinaryWriter writer = new(fs, Encoding.Default, leaveOpen: true);
				WriteClientData(writer, newClient);
			}
			else
			{
				Console.WriteLine($"Account #{accountNumber} already contains information.");
			}
		}

		static void DeleteRecord(FileStream fs)
		{
			int accountNumber = GetAccount("Enter account to delete");
			long position = (accountNumber - 1) * GetRecordSize();

			fs.Seek(position, SeekOrigin.Begin);
			using BinaryReader reader = new(fs, Encoding.Default, leaveOpen: true);
			ClientData client = ReadClientData(reader);

			if (client.AccountNumber != 0)
			{
				fs.Seek(position, SeekOrigin.Begin);
				using BinaryWriter writer = new(fs, Encoding.Default, leaveOpen: true);
				WriteClientData(writer, new ClientData());

				Console.WriteLine($"Account #{accountNumber} deleted.");
			}
			else
			{
				Console.WriteLine($"Account #{accountNumber} is empty.");
			}
		}

		static int GetAccount(string prompt)
		{
			int number;
			do
			{
				Console.Write($"{prompt} (1 - 100): ");
			} while (!int.TryParse(Console.ReadLine(), out number) || number < 1 || number > 100);
			return number;
		}

		static void WriteClientData(BinaryWriter writer, ClientData client)
		{
			writer.Write(client.AccountNumber);

			writer.Write(EncodeFixedString(client.LastName, 15));
			writer.Write(EncodeFixedString(client.FirstName, 10));

			writer.Write(client.Balance);
		}


		static byte[] EncodeFixedString(string input, int length)
		{
			string fixedStr = input.PadRight(length).Substring(0, length);
			return System.Text.Encoding.Unicode.GetBytes(fixedStr); // UTF-16LE: 2 bytes per char
		}

		static int GetRecordSize()
		{
			// int (4) + 15 * 2 + 10 * 2 + double (8)
			return sizeof(int) + (15 * 2) + (10 * 2) + sizeof(double);
		}


		static ClientData ReadClientData(BinaryReader reader)
		{
			int accountNumber = reader.ReadInt32();

			byte[] lastNameBytes = reader.ReadBytes(15 * 2);
			byte[] firstNameBytes = reader.ReadBytes(10 * 2);

			string lastName = Encoding.Unicode.GetString(lastNameBytes).Trim();
			string firstName = Encoding.Unicode.GetString(firstNameBytes).Trim();

			double balance = reader.ReadDouble();

			return new ClientData(balance, lastName, firstName, accountNumber);
		}


		static void OutputLineToConsole(ClientData record)
		{
			Console.WriteLine("{0,-10}{1,-16}{2,-11}{3,10:F2}",
					record.AccountNumber,
					record.LastName,
					record.FirstName,
					record.Balance);
		}

		static void OutputLine(TextWriter output, ClientData client)
		{
			output.WriteLine("{0,-10}{1,-16}{2,-11}{3,10:F2}",
					client.AccountNumber,
					client.LastName,
					client.FirstName,
					client.Balance);
		}

		// Credit card processing logic goes here
		// InData(filePath);
		// OutData(filePath);
		// Credit(filePath);
		Transactions(filePath);
	}
}
