#pragma once
namespace sqs
{
	template <typename Tn>
	void _sort(std::vector<Tn>& S, std::vector<Tn>& T, const size_t& start, const size_t& end, std::vector<Tn>& over)
	{
		size_t len = end - start;
		if (len < 1)return;
		if (len < 2)
		{
			over[start] = S[start];
			return;
		}
		size_t p = start;
		Tn& b = S[((start + end) / 2)];
		for (size_t i = start; i < end; ++i)
		{
			if (S[i] < b)
			{
				T[p++] = S[i];
			}
		}
		size_t size1 = p - start;
		for (size_t i = start; i < end; ++i)
		{
			if (S[i] == b)
			{
				over[p++] = S[i];
			}
		}
		size_t size2 = p - size1 - start;
		for (size_t i = start; i < end; ++i)
		{
			if (S[i] > b)
			{
				T[p++] = S[i];
			}
		}
		size_t size3 = p - size1 - size2 - start;
		/*
		if (size1 > size3)
		{
			_sort(T, S, start + size1 + size2, end, over);
			_sort(T, S, start, start + size1, over);
		}
		else
		{
			_sort(T, S, start, start + size1, over);
			_sort(T, S, start + size1 + size2, end, over);
		}*/
		_sort(T, S, start, start + size1, over);
		_sort(T, S, start + size1 + size2, end, over);
	}
	template <typename Tn>
	void sort(std::vector<Tn>& T)
	{
		std::vector<Tn> buffer(T.size());
		std::vector<Tn> over(T.size());
		_sort(T, buffer, 0, T.size(), over);
		T.assign(over.begin(), over.end());
	}
}
