import { useState, useEffect } from "react"
import axios from 'axios';

const baseURL = 'https://qghcujpqbvrdfszremfe.supabase.co/rest/v1/blogs?select=*'

const Form = () => {
    const [blogs, setBlogs] = useState(null)
    const [loading, setLoading] = useState(true)

    const[blogdata, setblogdata] = useState({title:"",
    description: "",
    author: "",
    reading_time: ""});

    const entry = () => {
        axios.post(baseURL,blogdata, {
            headers: {
                'Authorization': 'Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6InFnaGN1anBxYnZyZGZzenJlbWZlIiwicm9sZSI6ImFub24iLCJpYXQiOjE2NTgxMjk3NzcsImV4cCI6MTk3MzcwNTc3N30.LvOp9lASnuJAAwvg2VxFmnrVXuqZOM0KVngw8EKHQcM',
                'apikey': 'eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6InFnaGN1anBxYnZyZGZzenJlbWZlIiwicm9sZSI6ImFub24iLCJpYXQiOjE2NTgxMjk3NzcsImV4cCI6MTk3MzcwNTc3N30.LvOp9lASnuJAAwvg2VxFmnrVXuqZOM0KVngw8EKHQcM'
            }
        }).then((response) => {
            console.log("done")
        });
    }
    let key, value;

    const handleInput = (event) => 
    {  console.log(event)
        key = event.target.name;
        value = event.target.value;
        setblogdata({...blogdata, [key]:value})
    }


    return (<div>
    <div class="input-group mb-3">
    <input type="text" class="form-control" placeholder="Title" value={blogdata.title} name="title" id="title" onChange={handleInput} aria-label="Username" aria-describedby="basic-addon1"/>
  </div>
  
  <div class="input-group mb-3">
    <input type="text" class="form-control" placeholder="Description" name="description" id="description" value={blogdata.description} aria-label="Recipient's username" onChange={handleInput} aria-describedby="basic-addon2"/>
  </div>
  
  <div class="input-group mb-3">
    <input type="text" class="form-control" id="author" placeholder="Author" name="author"  value={blogdata.author} onChange={handleInput} aria-describedby="basic-addon3"/>
  </div>
  
  <div class="input-group mb-3">
   
    <input type="text" class="form-control" aria-label="Amount (to the nearest dollar)" id="reading_time" value={blogdata.reading_time} name="reading_time" placeholder="Reading time" onChange={handleInput}/>
    
  </div>

  <button type="button" class="btn btn-success" onClick={entry}>Submit</button>
  </div>
    )
}

export default Form