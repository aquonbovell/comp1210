using comp1210.Models;

namespace comp1210;

class Program
{
	static void Main(string[] args)
	{
		// Inhertiance();

		FileIO();

		// Recursion();

		// Sort();
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
}
