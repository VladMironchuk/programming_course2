let body = document.querySelector('body')

const module = (function(){
    //массив студентов с полями Имя, Фамилия, Возраст, Средний бал.
    let arr=[
        {
            name:'Serega',
            surname :'Harlanov',
            age : 18,
            avmark : 8.0,
        },
        {
            name:'Jan',
            surname :'Jasker',
            age : 18,
            avmark : 10.0,
        },
        {
            name:'Vlad',
            surname :'Rabets',
            age : 18,
            avmark : 9.0,
        },
        {  
            name:'Vlados',
            surname :'Kochurko',
            age : 18,
            avmark : 10.0,
        },
        {
            name:'Liza',
            surname :'Gradovich',
            age : 18,
            avmark : 10.0,
        }
    ]
   let keys = Object.keys(arr[0])
    function getValue(i,j){
        return Object.values(arr[i])[j];
    }
    return{
        getTable: function(){
           let table=body.appendChild(document.createElement('table'))
            for(let i=0;i<=arr.length;i++)
            {
               let tr=document.createElement('tr')
               table.appendChild(tr)
                if(i===0){
                    for(let j=0;j<keys.length;j++){
                       let th=document.createElement('th')
                        tr.appendChild(th)
                        th.innerText=keys[j]
                    }
                }
                else{
                    for(let j=0;j<keys.length;j++){
                       let td=document.createElement('td')
                        if(keys[j]==='avmark'){
                            td.className='avmark'
                        }
                        tr.appendChild(td)
                        td.innerText=getValue(i-1,j)
                    }
                }
            }
        },
        getAvMark: function(){
            let sum=0;
            let marks=document.querySelectorAll('.avmark')
            for(let i=0;i<marks.length;i++){
                let mark = +marks[i].innerText
                sum+=mark
            }
           let result = sum / arr.length
            return result.toFixed(2)
        }
    }
}() )

module.getTable()

div=body.appendChild(document.createElement('div'))
div.innerText="Average mark is " +  module.getAvMark()



