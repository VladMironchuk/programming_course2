let body = $('body')
let arr = []
$.getJSON('./students.json',function(data){
    arr = data
    const module = (function(){
       let keys = Object.keys(arr[0])
        function getValue(i,j){
            return Object.values(arr[i])[j];
        }
        return{
            getTable: function(){
                let table = $('<table>')
                body.append(table)
                for(let i=0;i<=arr.length;i++)
                {
                   let tr=$(`<tr id=${i}>`)
                   table.append(tr)
                    if(i===0){
                        for(let j=0;j<keys.length;j++){
                           let th=$('<th>')
                            tr.append(th)
                            th.text(keys[j])
                        }
                    }
                    else{
                        for(let j=0;j<=keys.length;j++){
                            if(j==keys.length){
                                let td = $('<td>')    
                                tr.append(td)
                                let button = $(`<button id =${i}>`)
                                td.append(button)
                                button.text('Delete')
                                button.css('width','67px')
                                button.click(module.removeString)
                            }
                            else{
                                let td=$('<td>')
                                if(keys[j]==='avmark'){
                                    td.addClass('avmark')
                                }
                                tr.append(td)
                                td.text(getValue(i-1,j))
                            }
                        }
                    }
                }
                return table
            },
            getAvMark: function(){
                let sum=0;
                let marks=$('.avmark')
                for(let i=0;i<marks.length;i++){
                    let mark = +marks.eq(i).text()
                    sum+=mark
                }
                let result = sum / arr.length
                return result.toFixed(2)
            },
            addString: function(){
                let arr1 = Array.from($('input'))
                arr1 = arr1.map((item)=> item.value)
                let table = $('table')
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
                let tr = $(`<tr id=${arr.length}>`)
                table.append(tr)
                for(let j=0;j<=keys.length;j++){
                    if(j==keys.length){
                        let td = $('<td>')
                        tr.append(td)
                        let button = $('<button>')
                        td.append(button)
                        button.text('Delete')
                        button.attr("id",arr.length)
                        button.css('width','67px')
                        button.click(module.removeString)
                    }
                    else{
                        let td=$('<td>')
                        if(keys[j]==='avmark'){
                            td.addClass('avmark')
                        }
                        tr.append(td)
                        td.text(getValue(arr.length-1,j))
                    }
                }
                div.text("Average mark is " +  module.getAvMark())
            },
            removeString: function(){
                let tr = Array.from($('tr'))
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
                        let a = +tr[i].id
                        tr[i].id = `${--a}`
                        let button = $(`#${i}`)
                        button.attr("id",a)
                    }
                }
                div.text("Average mark is " +  module.getAvMark())
            }
        }
    }() )
        module.getTable()
        let div = $('<div>')
        body.append(div)
        div.text("Average mark is " +  module.getAvMark())
    
        let divF = $('<div>')
        body.append(divF)
        divF.css('marginTop','30px')
    
        let pName = $('<p>')
        divF.append(pName)
        pName.text('Name')
        let sName = $('<span>')
        pName.append(sName)
        let iName = $('<input>')
        sName.append(iName)
        iName.css('marginLeft' ,'73px')
    
        let pSurname = $('<p>')
        divF.append(pSurname)
        pSurname.text('Surname')
        let sSurname = $('<span>')
        pSurname.append(sSurname)
        let iSurname = $('<input>')
        sSurname.append(iSurname)
        iSurname.css('marginLeft' , '54px')
    
        let pAge = $('<p>')
        divF.append(pAge)
        pAge.text('Age')
        let sAge = $('<span>')
        pAge.append(sAge)
        let iAge = $('<input>')
        sAge.append(iAge)
        iAge.css('marginLeft' ,'84px')
    
        let pAvmark = $('<p>')
        divF.append(pAvmark)
        pAvmark.text('Average mark')
        let sAvmark = $('<span>')
        pAvmark.append(sAvmark)
        let iAvmark = $('<input>')
        sAvmark.append(iAvmark)
        iAvmark.css('marginLeft' , '20px')
    
        let divB = $('<div>')
        divF.append(divB)
        let addButton = $('<button>')
        divB.append(addButton)
        addButton.text('Add Student')
        addButton.click(module.addString)
    
        let clearButton = $('<button>')
        divB.append(clearButton)
        clearButton.text('Clear')
        clearButton.css('marginLeft' , '137px')
        clearButton.click(clear)
        function clear(){
            let arr2 = Array.from($('input'))
            arr2.forEach((item)=>item.value='')
        }
})
