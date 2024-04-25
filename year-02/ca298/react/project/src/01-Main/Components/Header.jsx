
import { useRef } from "react";
import {FaBars, FaTimes} from "react-icons/fa";

function Header(){
    const navRef = useRef();

    const showNav = () => {
        navRef.current.classList.toggle("resposive_nav");
    }

    return(
        <header>
            <h3>Anime University</h3>
            <nav ref={navRef}>
                    <a href="/">Home</a>
                    <a href="/degrees">All Degrees</a>
                    <a href="/newdegree">New Degree</a>
                    <a href="/cohorts">All Cohorts</a>
                    <a href="/newcohort">New Cohort</a>
                    <a href="/modules">All Modules</a>
                    <a href="/newmodule">New Module</a>
                    <a href="/student">Student</a>
                    <a href="/newstudent">New Student</a>
                    <a href="/newstudentgrade">New Grade</a>
                    
                    <button className="nav-btn nav-close-btn" onClick={showNav}>
                        <FaTimes/>
                    </button>
            </nav>

            <button className="nav-btn" onClick={showNav}>
                <FaBars/>
            </button>
        </header>
    );
}

export default Header;