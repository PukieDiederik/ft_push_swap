let total=0
let num=0
let max=0;
let j=100


for ((i=0; i<j; i++))
do
	num=$(./push_swap `ruby -e "puts (0..500).to_a.shuffle.join(' ')"` | wc -l | xargs)
	if ((num > max))
	then
		((max=num))
	fi
	((total+=num))
done
echo "Average: " $((total / j))
echo "MAX:     " $max
