for ((i = 0 ; i < 100 ; i++)); do
  echo "Unittest No: $i"
  python3 input_generator.py > input.txt
  python3 wrong_solution.py < input.txt > output1.txt
  python3 ok_solution.py < input.txt > output2.txt
  diff output1.txt output2.txt || break
done
