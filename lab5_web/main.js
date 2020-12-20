let myApp = angular.module("MyApp",[])
    myApp.controller("AppController", function($scope, $http){
        let arr = []
        let keys
        $http.get('./student.json').then(function success(response){
            arr = response.data
            keys = Object.keys(arr[0])
            $scope.keys = keys
            $scope.students = arr
            $scope.getAvMark = function(){
                let sum = 0
                let marks = document.querySelectorAll('.avmark')
                marks.forEach((item) => sum += +item.innerText)
                let result = (sum / marks.length).toFixed(2)
                if(isNaN(result)){
                    return 'no students'
                }
                else{
                    return result
                }
            }
            $scope.addStudent = function(){
                let newStudent = Array.from(document.querySelectorAll('input'))
                newStudent = newStudent.map((item)=>item.value)
                if(!~newStudent.indexOf("") && !isNaN(+newStudent[2]) && !isNaN(+newStudent[3])){
                    let obj = {},i=0
                    for(key of keys){
                        i>1 ? obj[key] = +newStudent[i++] : obj[key] = newStudent[i++]
                    }
                    $scope.students.push(obj)
                }
                else{
                    alert('wrong info')
                    return;
                }
            }
            $scope.deleteStudent = function(){
                let j = this.$index
                $scope.students.splice(j,1)
            }
            $scope.editStudent = function(){
                let k = this.$index
                let field = prompt('enter a field to edit','')
                if(keys.indexOf(field)===-1){
                    alert('wrong field')
                    return;
                }
                let newValue = prompt('enter a new value','')
                if(field == 'age' || field == 'avmark'){
                    $scope.students[k][field] = +newValue}
                else{
                    $scope.students[k][field] = newValue
                }
            }

        })
    })