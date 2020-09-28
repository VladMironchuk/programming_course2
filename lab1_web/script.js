var arr=[];
let i=0,k;


//вводим массив
k = prompt('enter a massive of integer numbers','');
while(k != '' && k != null){
	arr[i++] = +k;
	k = prompt('enter a massive of integer numbers','');
}


//сортируем массив
for(let a = 0;a <arr.length; a++)
{
	for(let b = 0;b < arr.length-1; b++)
	{
		if(arr[b] > arr[b+1])
		{
			let swap = arr[b];
			arr[b] = arr[b+1];
			arr[b+1] = swap;
		}
	}
}


//вывод сортированного массива
console.log('отсортированный массив')
for(let a = 0;a < arr.length; a++){console.log(arr[a]);}


//вывод max и min элементов
let min = arr[0];
let max = arr[arr.length-1];
console.log('минимальный элемент : ', min);
console.log('максимальный элемент : ', max);


//вывод суммы элементов массива
let sum = 0;
for(let a = 0; a < arr.length; a++){sum += arr[a];}
console.log('сумма всех элементов : ', sum);