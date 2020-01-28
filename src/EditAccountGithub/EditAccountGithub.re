[@bs.val] external fetch: string => Js.Promise.t('a) = "fetch";

[@react.component]
let make = () => {
    
<>
    <div
      style={ReactDOMRe.Style.make(
        ~height="100%",
        ~width="100%",
        ~alignItems="center",
        ~justifyContent="center",
        ~paddingTop="50px",
        (),
      )}>
        <div> 
            {React.string("Status : ")} 
            <input id="Status" name="Status"/>
       </div>

        <button> {React.string("Valider")} </button>
    </div>
  </>;
}