<Query Kind="Program">
  <Namespace>System.Globalization</Namespace>
</Query>

void Main()
{
	Transformer transformer = new TransformerToEnglish();
	Foo(transformer);
	Thread.CurrentThread.CurrentCulture =CultureInfo.InvariantCulture;
}

//template method

public abstract class Transformer
{
	public string TransformToWords(double source)
	{
		bool value = SpecialCases.TryGetValue(source, out string result);

		if (value) return result;

		string sourceString = source.ToString(CultureInfo.InvariantCulture);

		var sb = new StringBuilder();

		for (int i = 0; i < sourceString.Length; i++)
		{
			sb.Append(Words[sourceString[i]] + (i < sourceString.Length - 1 ? " " : string.Empty));
		}

		return sb.ToString();
	}

	protected abstract Dictionary<char, string> Words { get; }

	protected abstract Dictionary<double, string> SpecialCases { get; }
}

public class TransformerToEnglish : Transformer
{
	protected override Dictionary<char, string> Words =>
		new Dictionary<char, string>()
	{
		{ '0', "zero" },
		{ '1', "one" },
		{ '2', "two" },
		{ '3', "three" },
		{ '4', "four" },
		{ '5', "five" },
		{ '6', "six" },
		{ '7', "seven" },
		{ '8', "eight" },
		{ '9', "nine" },
		{ '.', "point" },
		{ '-', "minus" },
		{ '+', "plus" },
		{ 'E', "e" },
		{ 'e', "e" }
	};

	protected override Dictionary<double, string> SpecialCases =>
 		new Dictionary<double, string>()
	{
		{ double.NaN,  "not a number" },
		{ double.PositiveInfinity, "positive infinity" },
		{ double.NegativeInfinity,  "negative infinity" },
	};
}

public static void Foo(Transformer transformer)
{
	$"{double.NaN} -> {transformer.TransformToWords(double.NaN)}".Dump();
	$"{-13.234400} -> {transformer.TransformToWords(-13.234400)}".Dump();
	$"{double.PositiveInfinity} -> {transformer.TransformToWords(double.PositiveInfinity)}".Dump();
}
