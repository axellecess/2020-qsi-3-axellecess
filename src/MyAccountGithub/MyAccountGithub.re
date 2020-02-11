[@bs.val] external fetch: string => Js.Promise.t('a) = "Fetch";

[@react.component]
let make = () => {

  let userData = () => {
    Js.Promise.(
      Fetch.fetchWithInit(
        "https://api.github.com/graphql",
        Fetch.RequestInit.make(
          ~method_=Get,
          ~headers=
            Fetch.HeadersInit.make(
              {
                "Authorization": "bearer 70d8164b83db14b67a5037396c06782bffbc45d4",
                "Content-Type": "application/x-www-form-urlencoded"
              }
            ),
          (),
        ))
        |> then_(Fetch.Response.json)
        |> then_(json => Js.log(json) |> resolve)
    );
  };



  userData();

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
      <div> <img /> </div>
      <div> {React.string("Nom : ")} </div>
      <div> {React.string("Status : ")} </div>
      <div> {React.string("Nombre de follower : ")} </div>
      <div> {React.string("Nnombre de following :")} </div>
    </div>
  </>;
};