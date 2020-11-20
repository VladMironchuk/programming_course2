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
               tr.id = `${i}`
               table.appendChild(tr)
                if(i===0){
                    for(let j=0;j<keys.length;j++){
                       let th=document.createElement('th')
                        tr.appendChild(th)
                        th.innerText=keys[j]
                    }
                }
                else{
                    for(let j=0;j<=keys.length;j++){
                        if(j==keys.length){
                            let td = tr.appendChild(document.createElement('td'))
                            let button = td.appendChild(document.createElement('button'))
                            button.innerText = 'Delete'
                            button.id = tr.id
                            button.style.width = '67px'
                            button.addEventListener('click',module.removeString)
                        }
                        else{
                            let td=document.createElement('td')
                            if(keys[j]==='avmark'){
                                td.className='avmark'
                            }
                            tr.appendChild(td)
                            td.innerText=getValue(i-1,j)
                        }
                    }
                }
            }
            return table
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
        },
        addString: function(){
            let arr1 = Array.from(document.querySelectorAll('input'))
            arr1 = arr1.map((item)=> item.value)
            let table = document.querySelector('table')
            let newObj = {}
            let i=0
            for(key of keys){
                if(key==='age' || key==='avmark'){
                    newObj[`${key}`] = +arr1[i++]
                }
                else{
                newObj[`${key}`] = arr1[i++]}
            }
            arr.push(newObj)
            let tr = table.appendChild(document.createElement('tr'))
            tr.id = `${arr.length}`
            for(let j=0;j<=keys.length;j++){
                if(j==keys.length){
                    let td = tr.appendChild(document.createElement('td'))
                    let button = td.appendChild(document.createElement('button'))
                    button.innerText = 'Delete'
                    button.id = tr.id
                    button.style.width = '67px'
                    button.addEventListener('click',module.removeString)
                }
                else{
                    let td=document.createElement('td')
                    if(keys[j]==='avmark'){
                        td.className='avmark'
                    }
                    tr.appendChild(td)
                    td.innerText=getValue(arr.length-1,j)
                }
            }
            div.innerText="Average mark is " +  module.getAvMark()
        },
        removeString: function(){
            let tr = Array.from(document.querySelectorAll('tr'))
            for(let i=0;i<tr.length;i++){
                if(tr[i].id == this.id){
                    if(i==tr.length-1){
                        arr.pop()
                        tr[i].remove()
                    }
                    else{
                    arr.splice(i-1,1)   
                    tr[i].remove()
                    }
                }
                if(tr[i].id > this.id){
                    (tr[i].id)
                    let a = +tr[i].id
                    tr[i].id = `${--a}`
                    let button = document.getElementById(i)
                    button.id = tr[i].id
                }
            }
            div.innerText="Average mark is " +  module.getAvMark()
        }
    }
}() )

module.getTable()
let div=body.appendChild(document.createElement('div'))
div.innerText="Average mark is " +  module.getAvMark()

let divF = body.appendChild(document.createElement('div'))
divF.style.marginTop = '30px'

let pName = divF.appendChild(document.createElement('p'))
pName.innerText = 'Name'
let sName = pName.appendChild(document.createElement('span'))
let iName = sName.appendChild(document.createElement('input'))
iName.style.marginLeft = '73px'

let pSurname = divF.appendChild(document.createElement('p'))
pSurname.innerText = 'Surname'
let sSurname = pSurname.appendChild(document.createElement('span'))
let iSurname = sSurname.appendChild(document.createElement('input'))
iSurname.style.marginLeft = '54px'

let pAge = divF.appendChild(document.createElement('p'))
pAge.innerText = 'Age'
let sAge = pAge.appendChild(document.createElement('span'))
let iAge = sAge.appendChild(document.createElement('input'))
iAge.style.marginLeft = '84px'

let pAvmark = divF.appendChild(document.createElement('p'))
pAvmark.innerText = 'Average mark'
let sAvmark = pAvmark.appendChild(document.createElement('span'))
let iAvmark = sAvmark.appendChild(document.createElement('input'))
iAvmark.style.marginLeft = '20px'

let divB = divF.appendChild(document.createElement('div'))
let addButton = divB.appendChild(document.createElement('button'))
addButton.innerText = 'Add Student'
addButton.addEventListener('click', module.addString)

let clearButton = divB.appendChild(document.createElement('button'))
clearButton.innerText = 'Clear'
clearButton.style.marginLeft = '137px'
clearButton.addEventListener('click', clear)
function clear(){
    let arr2 = Array.from(document.querySelectorAll('input'))
    arr2.forEach((item)=>item.value='')
}


