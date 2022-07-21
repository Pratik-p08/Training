import './App.css';
import Blogs from './components/Blogs';
import Form from './components/Form';

function App() {
  return (
    <div className="App">
      <h1>List of blogs</h1>
      <Blogs />
      <Form/>
    </div>
  );
}

export default App;
